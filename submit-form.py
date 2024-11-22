import requests
import os
from urllib.request import urlopen
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import Select # Import Select class
from selenium.common.exceptions import TimeoutException #Import TimeoutException
base_url ='https://olimpiada.ic.unicamp.br/pratique/ps/2021/f1/baralho/'
file_path = './teste.cpp'
file_path = os.path.abspath(file_path)
def submit_file(base_url, file_path):
    file_path = os.path.abspath(file_path)

    # Use selenium to handle delayed redirects
    options = webdriver.FirefoxOptions()
    options.add_argument('--headless')
    driver = webdriver.Firefox(options=options)

    driver.get(base_url)  # Navigate to the initial redirect URL
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