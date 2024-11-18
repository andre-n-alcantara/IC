import PyPDF2
import os

def pdf_to_text(pdf_path, output_path):
    # Open the PDF file in read-binary mode
    with open(pdf_path, 'rb') as pdf_file:
        # Create a PdfReader object instead of PdfFileReader
        pdf_reader = PyPDF2.PdfReader(pdf_file)

        # Initialize an empty string to store the text
        text = ''

        for page_num in range(len(pdf_reader.pages)):
            page = pdf_reader.pages[page_num]
            text += page.extract_text()

    # Write the extracted text to a text file
    with open(output_path, 'w', encoding='utf-8') as txt_file:
        txt_file.write(text)

def get_pdf(path):
    for file in os.listdir(path):
        if file.endswith('.pdf'):
            return file

def list_subfolders(folder_path):
    # Loop through the subfolders in the given folder path
    for root, dirs, files in os.walk(folder_path):
        for sub in dirs:
            sub_path = os.path.join(root, sub)
            pdf_path = os.path.join(sub_path, get_pdf(sub_path))
            output_path = os.path.join(sub_path, f"{sub}.txt")
            pdf_to_text(pdf_path, output_path)

for root, dirs, files in os.walk('./OBI'):
    for sub in dirs:
        sub_path = os.path.join(root, sub)
        list_subfolders(sub_path)