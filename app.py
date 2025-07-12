
from flask import Flask, render_template, request
import subprocess
import os

app = Flask(__name__)
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

@app.route('/', methods=['GET', 'POST'])
def index():
    encoded_text = ''
    decoded_text = ''
    original_size = 0
    compressed_size = 0
    compression_ratio = 0

    if request.method == 'POST':
        user_input = request.form['user_input']
        input_path = os.path.join(BASE_DIR, 'input.txt')
        with open(input_path, 'w') as f:
            f.write(user_input)

        subprocess.run(['g++', 'huffman.cpp', '-o', 'huffman.exe'], check=True)
        subprocess.run(['huffman.exe'], check=True)

        encoded_path = os.path.join(BASE_DIR, 'encoded.txt')
        decoded_path = os.path.join(BASE_DIR, 'decoded.txt')
        stats_path = os.path.join(BASE_DIR, 'compression_stats.txt')

        if os.path.exists(encoded_path):
            with open(encoded_path,'r') as f:
                encoded_text = f.read()

        if os.path.exists(decoded_path):
            with open(decoded_path, 'r') as f:
                decoded_text = f.read()

        if os.path.exists(stats_path):
            with open(stats_path, 'r') as f:
                lines = f.readlines()
                if len(lines) >= 3:
                    original_size = lines[0].split(':')[1].strip()
                    compressed_size = lines[1].split(':')[1].strip()
                    compression_ratio = lines[2].split(':')[1].strip()

    return render_template('index.html',
                           encoded=encoded_text,
                           decoded=decoded_text,
                           original_size=original_size,
                           compressed_size=compressed_size,
                           compression_ratio=compression_ratio)

if __name__ == '__main__':
    app.run(debug=True)
