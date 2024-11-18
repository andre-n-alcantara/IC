import os

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

