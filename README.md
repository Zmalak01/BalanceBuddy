# BalanceBuddy


A simple, menu-driven C++ console app to track expenses by category and manage balances for **Checking** and **Savings** accounts.

NOTE: Run on online compilers (example: gdb)

* ✅ Transfer **Savings → Checking** now actually updates balances
* ✅ Menu “invalid option” message says **1 → 12** (not 11)

---

## ✨ Features

* Set / view / edit **Checking** & **Savings** balances
* Add an expense (category + amount) and deduct from a chosen account
* View all expenses
* Delete a specific expense (refunds to **Checking** in this version)
* Transfer money between accounts
* Show the **highest** single expense
* Show **total** expenses
* Search by **category**
* Reset all expenses

---

## 🧰 Tech

* **Language:** C++ (C++11+ compatible)
* **Stdlib:** `<iostream>`, `<string>`, `<iomanip>`
* **Storage:** In-memory parallel arrays (no file/database persistence)

---

## 📦 Getting Started
## 🕹️ Usage

When you run the app, you’ll see:

```
---- Welcome To The Expenses Calculator! ----
1.  Assign Account Balances. 💳
2.  View Account Balances. 💰
3.  Edit Account Balances. ✏️
4.  Add An Expense. ➕.
5.  View Expenses. 👀
6.  Delete An Expense. 🚮
7.  Transfer money Between Accounts. 🔁
8.  View The Highest Expense. 🔝
9.  View An Expense Summary. 📝
10. Search For An Expense By Category. 🔍
11. Reset All Available Expenses. ♻️
12. Exit The Program. 👋
```

Type the option number and press **Enter**.

---

## 📁 Project Structure

```
.
├── main.cpp    # Application code (bugfix-only version)
└── README.md
```


## ⚠️ Known Limitations (intentional in this bugfix-only build)

* No data persistence (everything is in memory only)
* Monetary values use `float` (can round slightly)
* Category matching is case-sensitive
* Delete & search require exact matches
