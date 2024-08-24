import shutil
import json

assNo = 2

for j in range(assNo):

    ass = "ass"+str(j+1)
    loc = shutil.os.path.join("/home/dipendu/programs/mtech_2023/ml",ass)
    all = shutil.os.path.join(loc,"all")
    total = 27

    for i in range(total):
        folder_name = shutil.os.path.join(all, str(i+1))
        files = shutil.os.listdir(folder_name)
        substring_to_replace = "folder_number = \"9\""
        replacement_line = "folder_number = \""+str(i+1)+"\""
        for file_name in files:
            source_file = shutil.os.path.join(folder_name, file_name)
            if shutil.os.path.isfile(source_file):
                print("working on : ", source_file)

                def replace_string(cell_source):
                    return [line.replace(substring_to_replace, replacement_line) for line in cell_source]
                
                with open(source_file, "r", encoding="utf-8") as f:
                    notebook = json.load(f)
                for cell in notebook["cells"]:
                    if cell["cell_type"] == "code":
                        # Replace strings in code cells
                        cell["source"] = replace_string(cell["source"])
                    elif cell["cell_type"] == "markdown":
                        # Replace strings in markdown cells
                        cell["source"] = replace_string(cell["source"])

                # Write the modified notebook back to the file
                with open(source_file, "w", encoding="utf-8") as f:
                    json.dump(notebook, f, ensure_ascii=False, indent=1)
