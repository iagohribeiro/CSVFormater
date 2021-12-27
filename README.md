# CSVFormater

> **CSVFormater** formats the records in a CSV file to the standard "ASCII table".


So for an entry like the one below:

```
Name;Street;City;Age \
Peter Pan;Am Hang 5;12345 Einsam;42 \
Pedro Silva;Kölner Straße 45;50123 Köln;43 \
Paul Arantes;Münchener Weg 1;87654 München;65
```

It is converted to:
```
Name        |Street          |City         |Age|
------------+----------------+-------------+---+
Peter Pan   |Am Hang 5       |12345 Einsam |42 |
Maria Silva |Kölner Straße 45|50123 Köln   |43 |
Paul Arantes|Münchener Weg 1 |87654 München|65 |
```

------------


### How to compile
Open the **terminal** inside the `src` folder and use the command `make` or `make all`.

------------


### How to run
1. After following the **How to compile** steps, still inside the `src` folder, type the command `make run`.
2. The program will ask you for the file path. Then enter a path like the one shown below:
`/Users/{userName}/Documents/Project/data.csv`

------------

### How to delete unused files
Inside the `src` folder, type the command `make clean`.

------------

### Use the project in Eclipse
This project can be imported into **Eclipse**. To do this, download the repository or, through the GitHub link, import it into **Eclipse**.
