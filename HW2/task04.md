# Задание №4

## Доказать тождества

```sh
А → В = !A||B
```

<table>
    <tr>
        <th>A</th><th>B</th><th>А → В</th>
        <th> </th>
        <th>!A</th><th>B</th><th>!A||B</th>
    </tr>
    <tr>
        <td>0</td><td>0</td><td>1</td>
        <td> </td>
        <td>1</td><td>0</td><td>1</td>
    </tr>
    <tr>
        <td>0</td><td>1</td><td>1</td>
        <td> </td>
        <td>1</td><td>1</td><td>1</td>    </tr>
    <tr>
        <td>1</td><td>0</td><td>0</td>
        <td> </td>
        <td>0</td><td>0</td><td>0</td>    </tr>
    <tr>
        <td>1</td><td>1</td><td>1</td>
        <td> </td>
        <td>0</td><td>1</td><td>1</td>    </tr>
</table>

```sh
А ↔︎ В = (A && B) || (!A && !B)
```

<table>
    <tr>
        <th>A</th><th>B</th><th>А ↔︎ В</th>
        <th> </th>
        <th>A</th><th>B</th><th>(A && B)</th>
        <th>!A</th><th>!B</th><th>(!A && !B)</th>
        <th>(A && B) || (!A && !B)</th>
    </tr>
    <tr>
        <td>0</td><td>0</td><td>1</td>
        <td> </td>
        <td>0</td><td>0</td><td>0</td>
        <td>1</td><td>1</td><td>1</td>
        <td>1</td>
    </tr>
    <tr>
        <td>0</td><td>1</td><td>0</td>
        <td> </td>
        <td>0</td><td>1</td><td>0</td>
        <td>1</td><td>0</td><td>0</td>
        <td>0</td>
    </tr>
    <tr>
        <td>1</td><td>0</td><td>0</td>
        <td> </td>
        <td>1</td><td>0</td><td>0</td>
        <td>0</td><td>1</td><td>0</td>
        <td>0</td>
    </tr>
    <tr>
        <td>1</td><td>1</td><td>1</td>
        <td> </td>
        <td>1</td><td>1</td><td>1</td>
        <td>0</td><td>0</td><td>0</td>
        <td>1</td>
    </tr>
</table>