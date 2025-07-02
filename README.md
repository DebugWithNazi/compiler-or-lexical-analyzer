🧠 Compiler Design / Lexical Analyzer Assignment (C++)
For this assignment, I was responsible for implementing several core components of a compiler front-end using C++. Key features of the project included:

📂 File Handling: Initially, I enabled the program to read multiple source files as input.
🔤 Lexical Analysis: I developed a tokenizer that could break the input into characters, words, and meaningful tokens.
🧱 Environment Management: Whenever a new code block (like {}) was detected, a new environment was dynamically created.
📊 Symbol Table Integration: All variable declarations within each scope were stored in a symbol table with appropriate scoping.
🧬 Syntax Tree Construction: If the token matched a non-terminal, I generated a partial syntax tree. This included:
Syntax trees specifically for if statements and arithmetic expr expressions.
📦 Intermediate Code Generation: For if conditions, I implemented Three Address Code (TAC) generation to represent control flow and logical evaluation.

This assignment gave me hands-on experience with core compiler concepts such as tokenization, symbol table management, syntax analysis, and intermediate code generation — all using C++.
