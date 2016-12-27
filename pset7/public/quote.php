<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check if symbol is empty
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide the symbol you want to look up.");
        } 
        // check if symbol is valid
        else if (lookup($_POST["symbol"]) === false)  
            apologize("Couldn't find your quote symbol."); 
              
        else 
        {  
            $stock = lookup($_POST["symbol"]);
            $stock_rounded = floatval(number_format($stock["price"], $decimals = 4));
            render("quote.php", ["stock_rounded" => $stock_rounded,"title" => "Quote information"]);      
        }
    }
    else
    {
        // else render form
        render("quote_form.php", ["title" => "Search quote"]);   
    }

?>
