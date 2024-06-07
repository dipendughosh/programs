import hashlib

def generate_password_from_userid(user_id, length=12):
    hash_object = hashlib.sha256(user_id.encode())
    hex_dig = hash_object.hexdigest()
    # Ensure the length of the password
    password = hex_dig[:length]
    return password

user_id = 'cs23m509'
password = generate_password_from_userid(user_id, 12)
print(f'User ID: {user_id}, Password: {password}')
