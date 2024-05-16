import shutil

assNo = 2

for j in range(assNo):

    ass = "ass"+str(j+1)
    loc = shutil.os.path.join("/home/dipendu/programs/mtech_2023/ml",ass)
    all = shutil.os.path.join(loc,"all")
    total = 1

    for i in range(total):
        folder_name = shutil.os.path.join(all, str(i+1))
        files = shutil.os.listdir(folder_name)
        substring_to_replace = "folder_number = "
        replacement_line = "folder_number = \""+str(i+1)+"\""
        for file_name in files:
            source_file = shutil.os.path.join(folder_name, file_name)
            if shutil.os.path.isfile(source_file):
                print("working on : ", source_file)

                with open(source_file, "r+") as file:
                    lines = file.readlines()

                    file.seek(0)

                    for line in lines:
                        if substring_to_replace in line:
                            file.write(replacement_line)
                        else:
                            file.write(line)
