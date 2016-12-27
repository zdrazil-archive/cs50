<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
             <select name="symbol_sell">
                <option value="empty" selected="selected"></option>
                
                 <?php foreach ($stocks_owned as $symbol): ?>

                       <option ><?= $symbol["symbol"] ?></option>
                       
                 <? endforeach ?>

             </select>
        </div>
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Sell</button>
        </div>
    </fieldset>
</form>
