import requests
import os
import re
from urllib.request import urlopen
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import Select # Import Select class
from selenium.common.exceptions import TimeoutException, WebDriverException 
base_url ='https://olimpiada.ic.unicamp.br/pratique/'
root = './sol'
def get_url(base_url, file):
    pattern = re.compile(r'\d{4}')
    year = pattern.search(file).group()
    pattern = re.compile(r'p.')
    nivel = pattern.search(file).group()
    pattern = re.compile(r'f.-.*$')
    group = pattern.search(file).group()
    fase,name = group.split('-',1)
    name = name[:-4]
    if nivel=='pu':
        nivel='ps'
    return base_url+f'{nivel}/{year}/{fase}/{name}/'



def submit_file(base_url, file_path):
    file_path = os.path.abspath(file_path)

    # Use selenium to handle delayed redirects
    options = webdriver.FirefoxOptions()
    options.add_argument('--headless')

    firefox_path = 'C:/Program Files/Mozilla Firefox/firefox.exe'  # Update this path if necessary
    options.binary_location = firefox_path

    driver = webdriver.Firefox(options=options)

    try:
        driver.get(base_url)  # Navigate to the initial redirect URL
    except WebDriverException:
        print("URL not found")
        driver.quit()
        return

    select_elem = Select(driver.find_element(By.TAG_NAME, 'select'))
    for option in select_elem.options:
        if 'g++' in option.text or 'C++' in option.text:
            option.click()
            break
    file_input = driver.find_element(By.NAME, 'data')
    file_input.send_keys(file_path)

    driver.find_element(By.TAG_NAME, 'form').submit()
    # Wait for the final redirect (adjust timeout as needed)
    try:
        final_url = WebDriverWait(driver, 30).until(
            EC.url_contains('resultado')  # Wait for URL to change
        )

        # Find the <center> element and print its inner text
        center_element = driver.find_element(By.TAG_NAME, 'center')
        print(center_element.text)
    except TimeoutException:
        print("Timeout waiting for redirect.")

    driver.quit()  # Close the browser

for file in os.listdir(root)[:2]:
    url = get_url(base_url, file)
    submit_file(url, os.path.join(root, file))