import requests
import json

# Make a GET request to GitHub API
response = requests.get('https://api.github.com/users/pulkito4')

# Display the response content
print(f"Status Code: {response.status_code}")
print("------------------------------")
print(json.dumps(response.json(), indent=2, sort_keys=True))