# enqueue_deque
 
This project implements AES-128 encryption and decryption in C. It includes two programs:

- `encrypt`: Encrypts plaintext files using a 16-byte key.
- `decrypt`: Decrypts ciphertext files using the same 16-byte key.

AES (Advanced Encryption Standard) is a symmetric block cipher that operates on 16-byte blocks using a 16-byte key.

Usage

To encrypt a file:

    ./encrypt key.dat plaintext.dat ciphertext.dat

To decrypt a file:

    ./decrypt key.dat ciphertext.dat plaintext-output.dat

Requirements

- Key file: Must contain exactly 16 bytes.
- Input file: Must be a multiple of 16 bytes in size.
- Output: Encryption results in binary output, typically unreadable as text.

Error Handling

- If any file cannot be opened:

      Can't open file: <filename>

- If the key file is not 16 bytes:

      Bad key file: <key-filename>

- If the input plaintext or ciphertext file is not a multiple of 16 bytes:

      Bad plaintext file length: <filename>
      Bad ciphertext file length: <filename>

File Types

- `.dat` extension used for all files to indicate data content (may be binary or ASCII).
- Text editors can open key and plaintext files.
- Use `hexdump -C` to view binary ciphertext.

Examples

Encrypt:

    $ cat key-01.dat
    abcdefgh1234567

    $ cat plain-01.dat
    one fish
    2 fish

    $ ./encrypt key-01.dat plain-01.dat cipher-output.dat
    $ hexdump -C cipher-output.dat
    00000000 93 89 d1 2e db e8 aa 7c 2b 6b 2f a7 43 29 84 6f |.......|+k/.C).o|

Decrypt:

    $ ./decrypt key-01.dat cipher-output.dat plain-output.dat
    $ diff plain-output.dat plain-01.dat
