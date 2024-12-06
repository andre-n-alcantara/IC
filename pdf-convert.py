import os
import re
from multilingual_pdf2text.pdf2text import PDF2Text
from multilingual_pdf2text.models.document_model.document import Document

def pdf_to_text(pdf_path, output_path):
    ## create document for extraction with configurations
    pdf_document = Document(
        document_path=pdf_path,
        language='por'
        )
    pdf2text = PDF2Text(document=pdf_document)
    content = [page['text'] for page in pdf2text.extract()]
    text = ' '.join(content)
    with open(output_path, 'w', encoding='utf-8') as f:
        f.write(text)

def get_pdf(path):
    for file in os.listdir(path):
        if file.endswith('.pdf'):
            return file
        
def list_subfolders(root):
    # Loop through the subfolders in the given folder path
    for sub in os.listdir(root):
        if not os.path.isdir(os.path.join(root,sub)):
            continue
        sub_path = os.path.join(root, sub)
        pdf_path = os.path.join(sub_path, get_pdf(sub_path))
        output_path = os.path.join(sub_path, f"{sub}-pdf.txt")
        pdf_to_text(pdf_path, output_path)

root = './OBI'
for sub in os.listdir(root):
    if not os.path.isdir(os.path.join(root,sub)):
        continue
    sub_path = os.path.join(root, sub)
    list_subfolders(sub_path)

!pip install PyMuPDF
!pip install pylatexenc

import fitz
import re
from pylatexenc.latex2text import LatexNodes2Text

def extract_text_from_pdf(pdf_path):
    doc = fitz.open(pdf_path)
    text = ""
    for page in doc:
        text += page.get_text()

    # Remove LaTeX commands
    text = re.sub(r"\\begin\{.*?\}", "", text)  # Remove \begin{} blocks
    text = re.sub(r"\\end\{.*?\}", "", text)  # Remove \end{} blocks
    text = re.sub(r"\\.*?\{.*?\}", "", text)  # Remove commands with arguments

    # Convert LaTeX symbols
    text = LatexNodes2Text().latex_to_text(text)

    return text.encode('utf-8').decode('utf-8')  # Ensure UTF-8 encoding

# Example usage
pdf_path = 'your_pdf_file.pdf'  # Replace with your PDF file path
extracted_text = extract_text_from_pdf(pdf_path)
print(extracted_text)