<?php
    require_once('data_base.php');
    if ($_SESSION['logged_in'] == true)
        redirect('camagru.php');
    if ($_POST && $_POST['Username'] && $_POST['Password'] && $_POST['Email'] && $_POST['Password_check']
        && $_POST['Username'] != "" && $_POST['Password'] != ""
        && $_POST['Email'] != "" && $_POST['Password_check'] != "")
    {
        $hash = hash('sha512', htmlentities($_POST['Password']));
        $query = 'SELECT * FROM users WHERE username = ? OR password = ? OR mail = ?';
        $prep = $pdo->prepare($query);
        
        $prep->bindValue(1, htmlentities($_POST['Username']), PDO::PARAM_STR);
        $prep->bindValue(2, $hash, PDO::PARAM_STR);
        $prep->bindValue(3, htmlentities($_POST['Email']), PDO::PARAM_STR);
        
        $prep->execute();
        $arr = $prep->fetch();
        $pass = htmlentities($_POST['Password']);

        if($arr !== false)
        {
            while ($arr)
            {
                if ($arr['mail'] == $_POST['Email'])
                {
                    $_POST['Email'] = null;
                    $_POST['error_mail'] = "Cet adresse email est déjà utilisée";
                }
                if ($arr['password'] == $hash)
                {
                    $_POST['Password'] = null;
                    $_POST['error_pwd'] = "Ce mot de passe est déjà utilisé";
                }
                if ($arr['username'] == $_POST['Username'])
                {
                    $_POST['Username'] = null;
                    $_POST['error_user'] = "Ce nom d'utilisateur est déjà utilisé";
                }
                $arr = $prep->fetch();
            }
        }
        else if (preg_match('/[a-z]/', $pass) && preg_match('/[0-9]/', $pass) &&
                    preg_match('/[A-Z]/', $pass) &&
                    $pass == htmlentities($_POST['Password_check']))
        {
            $hash = hash('sha512', $pass);
            $query = 'INSERT INTO users (username, password, mail, active, sexe) VALUES (?, ?, ?, ?, ?)';
            $prep = $pdo->prepare($query);
            $prep->bindValue(1, htmlentities($_POST['Username']), PDO::PARAM_STR);
            $prep->bindValue(2, $hash, PDO::PARAM_STR);
            $prep->bindValue(3, htmlentities($_POST['Email']), PDO::PARAM_STR);
            $prep->bindValue(4, 0, PDO::PARAM_INT);
            $prep->bindValue(5, (intval($_POST['sexe']) == 0 ? 0 : 1), PDO::PARAM_INT);
            $prep->execute();
            $cle = $pdo->lastInsertId();
            $subject = "Mail d'activation de compte Camagru";
            $entete = "From : mlevieux42@gmail.com";
            $message = "Voici le lien d'activation de votre compte Camagru.\n
                        Pour toute question concernant nos conditions d'utilisation ou autre,
                        veuillez utiliser la rubrique contact de notre site.
                        \n\nCliquez sur le lien pour activer votre compte :\n
                        http://localhost:8080/Camagru/activation.php?login="
                        .urlencode(htmlentities($_POST['Username']))."&cle=".urlencode(hash('sha512', $cle)).
                        "\nCeci est un message automatique, merci de ne pas répondre.";
            mail(htmlentities($_POST['Email']), $subject, $message, $entete);
            $_POST['Username'] = null;
            $_POST['Password'] = null;
            $_POST['Password_check'] = null;
            $_POST['Email'] = null;
            $_POST['error_user'] = null;
            $_POST['error_mail'] = null;
            $_POST['error_pwd'] = null;
            echo '<script>alert("Votre inscription a bien été effectuée, un mail d\'activation vous a été envoyé");</script>';
        }
        else if ($pass != htmlentities($_POST['Password_check']))
            $_POST['error_passwords_not_identical'] = "Les deux mots de passe doivent etre identiques";
        else
            $_POST['error_not_secure'] = "Le mot de passe doit contenir au moins une minuscule, une majuscule et un chiffre";
    }
    else if ($_POST && ($_POST['Username'] == "" || $_POST['Password'] == "" || $_POST['Email'] == ""))
        $_POST['error_not_filled'] = "Vous devez remplir tous les champs marqués d'une '*' pour vous inscrire!";
?>    

<html>
    <head>
        <link rel="stylesheet" type="text/css" href="inscription.css">
        <title>
            Inscription
        </title>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    </head>
    <body>
        <div id="connexion">
            <a href="connexion.php">En fait je suis déjà inscrit...</a>
        </div>
        <h1 style="margin-top:6vmin;">WELCOME USER</h1>
        <div id="inscription">
            <table id="table_form">
                <form method="post" action="inscription.php">
                <tr>
                    <td>Veuillez choisir un nom d'utilisateur* : <input 
                    <?php
                        if (isset($_POST['error_user']))
                            echo 'style="background:#F5A9A9";';
                        else if (isset($_POST['Username']))
                            echo ' value="'.$_POST['Username'].'"';
                    ?>
                    type="text" name="Username" minlength=6 maxlength=30/></td>
                </tr>
                <tr>
                    <td>Veuillez choisir un mot de passe* : <input
                    <?php
                        if (isset($_POST['error_pwd']))
                            echo 'style="background:#F5A9A9";';
                        else if (isset($_POST['Password']))
                            echo ' value="'.$_POST['Password'].'"';
                    ?>
                    type="password" name="Password" minlength=8 maxlength=60/></td>
                </tr>
                <tr>
                    <td>Veuillez retaper votre mot de passe* : <input
                    <?php
                        if (isset($_POST['error_pwd']))
                            echo 'style="background:#F5A9A9";';
                        else if (isset($_POST['Password_check']))
                            echo ' value="'.$_POST['Password_check'].'"';
                    ?>
                    type="password" name="Password_check" minlength=8 maxlength=60/></td>
                </tr>
                <tr>
                    <td>Veuillez renseigner votre email* : <input
                    <?php
                        if (isset($_POST['error_mail']))
                            echo 'style="background:#F5A9A9";';
                        else if (isset($_POST['Email']))
                            echo ' value="'.$_POST['Email'].'"';
                    ?>
                    type="email" name="Email" minlength=7/></td>
                </tr>
                <tr>
                    <td>Êtes-vous un homme ou une femme? : <br/>
                        &nbsp&nbsp&nbsp&nbspUn Homme<input type="radio" name="sexe" value=1/> <br/>
                        &nbsp&nbsp&nbsp&nbspUne Femme<input type="radio" name="sexe" value=0/>
                    </td>
                </tr>
                <tr>
                    <td><span id="precision">Les champs marqués d'une astérixe ('*') sont obligatoires
                        <br/>Le mot de passe choisi doit contenir au minimum 8 caractères
                        <br/>Le nom d'utilisateur choisi doit contenir au minimum 6 caractères</span></td>
                </tr>
                <?php
                    if (isset($_POST['error_user']) || isset($_POST['error_pwd']) || isset($_POST['error_mail'])
                        || isset($_POST['error_not_filled']) || isset($_POST['error_not_secure']) ||
                        isset($_POST['error_passwords_not_identical']))
                    {
                        echo    '<tr id="warning">
                                    <td>
                                        <p>'.$_POST['error_user'].'</p>'.
                                        '<p>'.$_POST['error_pwd'].'</p>'.
                                        '<p>'.$_POST['error_mail'].'</p>'.
                                        '<p>'.$_POST['error_not_filled'].'</p>'.
                                        '<p>'.$_POST['error_passwords_not_identical'].'</p>'.
                                        '<p>'.$_POST['error_not_secure'].'</p>
                                    </td>
                                </tr>';
                    }
                ?>
                <tr>
                    <td>
                        <button id="validate" type="submit" name="OK">
                            <span id="first">OK</span>
                            <span id="second">C'est Parti!</span>
                            <span id="third">Wouhou!!</span>
                        </button>
                    </td>
                </tr>
                </form>
            </table>
        </div>
    </body>
</html>