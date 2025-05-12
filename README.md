💰 Bank Account Management System
A C++ console application that simulates a simple banking system. This project includes features such as user login/signup, balance tracking for Savings and Checkings accounts, and persistent data storage using text files.

📌 Features
🔐 Login & Signup System
Users can create new accounts or log in using a secure text-based credential system (Passwords.txt).

🏦 Savings and Checkings Accounts
Each user has access to both account types, supporting:

- Deposits

- Withdrawals

- Balance display

💾 Persistent Balance Storage
Account balances and transaction counts are saved to Balances.txt and automatically loaded upon login.

🔁 Money Transfers
Users can send money to other users by providing a recipient ID.

📊 Transaction Count
Automatically tracks the number of transactions (deposits/withdrawals) per account.

🛠️ Technologies Used
C++
Object-oriented design with inheritance and abstract base classes.

File I/O
Text-based storage of user credentials and balances.

📌 Example Use Cases
A user logs in and deposits $1000 into their savings account.

They withdraw $200 from checkings.

Transfers $100 to another user using their ID.

Balances are saved and available next time the program is run.

📚 Learning Objectives
This project helped demonstrate:

Abstract classes and inheritance

File input/output in C++

Menu-driven console applications

Basic authentication and data persistence
