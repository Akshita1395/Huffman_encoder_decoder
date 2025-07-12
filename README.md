##  About the Project

This is a simple **Huffman Encoder & Decoder** project built using:

*  C++ (for Huffman logic)
*  Python Flask (for connecting backend to frontend)
*  HTML, CSS, JS (for clean UI)

The project allows users to **type or upload a message**, and it will:

* Compress the message using Huffman Coding
* Show the encoded and decoded output
* Display compression stats and a visual bar

It is designed to be beginner-friendly and viva-ready.

---

##  How to Run (Windows CMD)

###  1. Install Requirements

Make sure you have the following:

| Tool                 | Install With                                                                                      |
| -------------------- | ------------------------------------------------------------------------------------------------- |
|  Python             | [Download from python.org](https://www.python.org/downloads/)                                     |
|  pip                | Comes with Python                                                                                 |
|  Flask              | Install by running: `pip install flask`                                                           |
|  g++ (C++ compiler) | Install [TDM-GCC](https://jmeubank.github.io/tdm-gcc/) or [MinGW-w64](https://www.mingw-w64.org/) |

---

###  2. Folder Structure

```
project-folder/
│
├── app.py
├── huffman.cpp
├── input.txt
├── encoded.txt
├── decoded.txt
├── compression_stats.txt
│
├── templates/
│   └── index.html
│
└── static/
    └── style.css
```

Make sure this folder structure is correct.
(Flask needs `templates/` and `static/` folders exactly like this.)

---

###  3. Steps to Run via CMD

Open **Command Prompt** in your project folder.

```bash
cd path-to-your-project-folder
```

Then run:

```bash
g++ huffman.cpp -o huffman.exe
python app.py
```

Once Flask runs, it will show:

```
Running on http://127.0.0.1:5000
```

Open that link in your browser.

---

###  What Happens Next:

1. Type or upload a message in the input box
2. Click **“Send & Compress”**
3. You'll see:

   *  Encoded Text
   *  Decoded Text
   *  Compression Stats
   *  Visual compression bar

---

##  What I Learned

* How Huffman Coding works using min-heap and binary tree
* Connecting C++ logic to a frontend using Python Flask
* Creating a clean and modern UI with HTML, CSS
* Using `subprocess` to run C++ from Python


