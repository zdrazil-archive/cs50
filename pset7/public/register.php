<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check if username is empty
        if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
        // check if username or password is empty
        else if (empty($_POST["password"]) || empty($_POST["confirmation"]))
        {
            apologize("You must provide password and confirm that password.");
        }
        // check if password and confimartion password match
        else if ($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Your passwords don't match.");
        }
        else 
           
            // insert user data to a table and  check if username already exists
            $result = query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)", $_POST["username"], crypt($_POST["password"]));
            if ($result === false)
                 apologize("Username already exists. Try a different name.");
 
            // login user the new user
            
            // find out user id
            $rows = query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];
            
            // store user id in session 
             $_SESSION["id"] = $id;
            
            // redirect to portfolio
            redirect("/");
    }
    else
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

?>
