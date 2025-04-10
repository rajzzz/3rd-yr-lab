import requests
from bs4 import BeautifulSoup
import sqlite3

# Step 1: Connect to SQLite database (or create one in the same folder)
conn = sqlite3.connect('quotes.db')
cursor = conn.cursor()

# Step 2: Create a table
cursor.execute('''
    CREATE TABLE IF NOT EXISTS quotes (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        quote TEXT,
        author TEXT
    )
''')
conn.commit()

# Step 3: Scrape the website
url = 'https://quotes.toscrape.com/'
response = requests.get(url)

if response.status_code == 200:
    soup = BeautifulSoup(response.text, 'html.parser')
    
    quote_elements = soup.find_all('div', class_='quote')
    
    for quote_element in quote_elements:
        quote_text = quote_element.find('span', class_='text').get_text(strip=True)
        author = quote_element.find('small', class_='author').get_text(strip=True)
        
        # Step 4: Insert into database
        cursor.execute('INSERT INTO quotes (quote, author) VALUES (?, ?)', (quote_text, author))

    conn.commit()
    print("Quotes inserted into database successfully!")
else:
    print("Failed to fetch the webpage.")

# Step 5: Fetch and display the quotes from database
print("\nQuotes stored in the database:\n")
cursor.execute('SELECT id, quote, author FROM quotes')
rows = cursor.fetchall()

for row in rows:
    print(f"{row[0]}. {row[1]} - {row[2]}")

# Step 6: Close the connection
conn.close()
