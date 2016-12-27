<div>
    <form action="index.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autofocus class="form-control" name="symbol" placeholder="Stock's name" type="text"/>
        </div>
        <div class="form-group">
            <input autofocus class="form-control" name="shares" placeholder="Number of shares" type="text"/>
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Buy</button>
        </div>
    </fieldset>
</form>
</div>
<div>
<table>
    <tr>
        <td>Cash</td>
        <td><?= $cash_row[0]["cash"] ?> USD</td>
    </tr/
    <tr>
        <td>Stock</td>
        <td>Symbol</td>
        <td>Number of shares</td>
        <td>Price</td>
    </tr>
    <?php foreach ($positions as $position): ?>

    <tr>
        <td><?= $position["name"] ?></td>
        <td><?= $position["symbol"] ?></td>
        <td><?= $position["shares"] ?></td>
        <td><?= $position["price"] ?></td>
    </tr>

    <? endforeach ?>
</table>
</div>
<div>
    <a href="logout.php">Log Out</a>
</div>
