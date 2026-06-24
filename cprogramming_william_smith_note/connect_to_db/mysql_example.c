// #include <mysql.h> // MySQL API functions
#include <mysql/mysql.h>
#include <stdio.h> // printf(), fprintf()

int main() {

  /************************************************************
   * STEP 1: INITIALIZE MYSQL OBJECT
   ************************************************************/

  // Create a MYSQL connection object
  MYSQL *con = mysql_init(NULL);

  // Check if initialization failed
  if (con == NULL) {
    fprintf(stderr, "mysql_init() failed\n");
    return 1;
  }

  /************************************************************
   * STEP 2: CONNECT TO MYSQL SERVER
   ************************************************************/

  // Connect to database
  // Parameters:
  // 1. MYSQL object
  // 2. Hostname
  // 3. Username
  // 4. Password
  // 5. Database name
  // 6. Port (0 = default 3306)
  // 7. Unix socket (NULL = default)
  // 8. Client flags (0 = none)
  if (mysql_real_connect(con, "localhost", "root", "Bassguitar1", "school2", 0,
                         NULL, 0) == NULL) {

    fprintf(stderr, "Connection failed: %s\n", mysql_error(con));
    mysql_close(con);
    return 1;
  }

  printf("Connected to MySQL successfully.\n");

  /************************************************************
   * STEP 3: EXECUTE A CREATE TABLE QUERY
   ************************************************************/

  if (mysql_query(
          con,
          "CREATE TABLE IF NOT EXISTS Cars(Id INT, Name TEXT, Price INT)")) {

    fprintf(stderr, "Create table failed: %s\n", mysql_error(con));
    mysql_close(con);
    return 1;
  }

  printf("Table checked/created successfully.\n");

  /************************************************************
   * STEP 4: INSERT DATA (Optional Example)
   ************************************************************/

  if (mysql_query(con, "INSERT INTO Cars VALUES(1, 'BMW', 50000)")) {

    fprintf(stderr, "Insert failed: %s\n", mysql_error(con));
    mysql_close(con);
    return 1;
  }

  printf("Data inserted successfully.\n");

  /************************************************************
   * STEP 5: SELECT DATA
   ************************************************************/

  if (mysql_query(con, "SELECT * FROM Cars")) {

    fprintf(stderr, "Select failed: %s\n", mysql_error(con));
    mysql_close(con);
    return 1;
  }

  // Store the complete result set in memory
  MYSQL_RES *result = mysql_store_result(con);

  // Check if result retrieval failed
  if (result == NULL) {
    fprintf(stderr, "Result retrieval failed: %s\n", mysql_error(con));
    mysql_close(con);
    return 1;
  }

  /************************************************************
   * STEP 6: FETCH AND PRINT ROWS
   ************************************************************/

  MYSQL_ROW row; // Row is an array of strings

  while ((row = mysql_fetch_row(result))) {

    // row[0] = Id
    // row[1] = Name
    // row[2] = Price
    printf("Id: %s, Name: %s, Price: %s\n", row[0], row[1], row[2]);
  }

  // Free memory used by result set
  mysql_free_result(result);

  /************************************************************
   * STEP 7: CLOSE CONNECTION
   ************************************************************/

  mysql_close(con);

  printf("Connection closed.\n");

  return 0;
}

// sudo apt-get install libmysqlclient-dev
// compile with:
// gcc mysql_example.c -o main -lmysqlclient
// gcc mysql_example.c -o main $(mysql_config --cflags --libs)
// run with: ./main

/************************************************************
 * MySQL Database Example in C
 * Uses MySQL Connector/C
 ************************************************************/
