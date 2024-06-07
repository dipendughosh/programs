import hashlib
import base64

def generate_password(user_id):
    # Create a SHA-256 hash of the user ID
    hash_object = hashlib.sha256(user_id.encode())
    hash_digest = hash_object.digest()
    
    # Encode the hash using base64 to make it more readable
    base64_encoded = base64.urlsafe_b64encode(hash_digest).decode('utf-8')
    
    # Ensure the password has the desired length (12 characters in this case)
    password = base64_encoded[:12]
    
    return password

user_id = 'cs23m509'
password = generate_password(user_id)
print(f'User ID: {user_id}, Password: {password}')
