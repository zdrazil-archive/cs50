<?php

    // configuration
    require("../includes/config.php");
    

    
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
    
        // calculate how much the stocks are worth
        $lookup_price = lookup($_POST["symbol_sell"]);
        $worth = $lookup_price["price"];
        $lookup_amount = query("SELECT shares FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol_sell"]);
        $amount = $lookup_amount[0]["shares"];
        $profit = $amount * $worth;
        
        // remove stock from portfolio
        query("DELETE FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol_sell"]);
        
        // update cash
        query("UPDATE users SET cash = cash + $profit WHERE id = ?", $_SESSION["id"]);
        
        // redirect to portfolio
        redirect("/");
           
    }
    else 
    {
        // else find user's stocks
        $rows = query("SELECT symbol FROM portfolio WHERE id = ?", $_SESSION["id"]);
        $stocks_owned = [];
        foreach ($rows as $row)
        {
            $stock = lookup($row["symbol"]);
            if ($stock !== false)
            {
                $stocks_owned[] = [
                    "symbol" => $row["symbol"]
                ];
            }
        }
        
        // TODO Apologize if no stocks to sell
        
        // render sell form
        render("sell.php", ["stocks_owned" => $stocks_owned, "title" => "Sell Stock"]);
    }

?>





// display form
// get stock to sell


//remove stock from portfolio
DELETE FROM portfolio WHERE id = 7 AND symbol = "AAPL"
 
// update cash


