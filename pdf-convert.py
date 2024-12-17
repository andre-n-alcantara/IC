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