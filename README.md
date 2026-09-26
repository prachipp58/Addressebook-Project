[README (1).md](https://github.com/user-attachments/files/32678232/README.1.md)
# 📇 AddressBook — CLI Contact Manager in C

A lightweight, file-persistent **Address Book application** written in pure C. Manage your contacts straight from the terminal — create, search, edit, delete, and list them, with built-in validation and automatic save/load to disk.

<p align="left">
  <img src="https://img.shields.io/badge/language-C-blue.svg" alt="Language: C">
  <img src="https://img.shields.io/badge/platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey.svg" alt="Platform">
  <img src="https://img.shields.io/badge/build-gcc-orange.svg" alt="Build: gcc">
  <img src="https://img.shields.io/badge/license-MIT-green.svg" alt="License: MIT">
</p>

---

## ✨ Features

- **➕ Create Contact** — add a name, phone number, and email with real-time input validation
- **🔍 Search Contact** — look up contacts by name, phone number, or email
- **✏️ Edit Contact** — update any field of an existing contact
- **🗑️ Delete Contact** — remove a contact with a confirmation prompt
- **📋 List Contacts** — view every saved contact in a clean, formatted layout
- **💾 Persistent Storage** — contacts are automatically saved to and loaded from `contacts.txt`
- **✅ Input Validation**
  - Names: letters and spaces only
  - Phone numbers: exactly 10 digits, must be unique
  - Emails: must contain a valid `@` and `.` structure, and be unique

---

## 🗂️ Project Structure

```
AddressBook-NewDesign/
├── main.c          # Entry point — menu loop and user interaction
├── contact.c       # Core logic: create, search, edit, delete, list, validation
├── contact.h       # Contact & AddressBook struct definitions and function declarations
├── file.c          # File I/O — save/load contacts to/from contacts.txt
├── file.h          # File I/O function declarations
├── populate.c      # Optional dummy data generator for testing
├── populate.h      # Populate function declaration
└── contacts.txt    # Data file where contacts are persisted
```

---

## 🚀 Getting Started

### Prerequisites

- A C compiler (`gcc` recommended)
- Works on Linux, macOS, or Windows (via WSL/MinGW)

### Build

```bash
git clone https://github.com/<your-username>/AddressBook-NewDesign.git
cd AddressBook-NewDesign
gcc main.c contact.c file.c populate.c -o addressbook
```

### Run

```bash
./addressbook
```

---

## 🖥️ Usage

On launch, you'll see a simple menu:

```
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save and Exit
Enter your choice:
```

Simply enter the number corresponding to the action you want to perform and follow the on-screen prompts. All changes are written to `contacts.txt` when you choose **Save and Exit**, so your contacts persist between sessions.

---

## 🛣️ Roadmap

- [ ] Sort contacts alphabetically or by field in `listContacts`
- [ ] Support dynamic contact storage instead of a fixed `MAX_CONTACTS`
- [ ] Add unit tests for validation functions
- [ ] Improve CLI UX with colorized output

---

## 🤝 Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request for bug fixes, new features, or improvements.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

---

## 📄 License

This project is licensed under the MIT License — feel free to use, modify, and distribute it.

---

<p align="center">Made with ❤️ and C</p>
