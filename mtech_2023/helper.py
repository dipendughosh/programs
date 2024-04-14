import os
import shutil

def rename_files(folder_path):
    # Traverse through the directory structure
    for root, dirs, files in os.walk(folder_path):
        for filename in files:
            # Rename files by replacing newline characters with spaces
            old_filepath = os.path.join(root, filename)
            new_filename = filename.replace('\n', ' ')
            new_filepath = os.path.join(root, new_filename)
            os.rename(old_filepath, new_filepath)

# Specify the source and destination folders
source_folder = '/home/dipendu/programs/mtech_2023/ml/ass2/raunak'
destination_folder = '/home/dipendu/programs/mtech_2023/ml/ass2/temp'

# Check if the destination folder exists
if os.path.exists(destination_folder):
    # Perform the file renaming operation directly
    rename_files(destination_folder)
else:
    # Copy the source folder to the destination folder
    shutil.copytree(source_folder, destination_folder)

    # Apply the file renaming operation on the copied folder
    rename_files(destination_folder)

