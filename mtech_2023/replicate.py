import shutil

assNo = 2

for j in range(assNo):

    ass = "ass"+str(j+1)
    loc = shutil.os.path.join("/home/dipendu/programs/mtech_2023/ml",ass)
    all = shutil.os.path.join(loc,"all")
    if shutil.os.path.isdir(all):
        shutil.rmtree(all)
    shutil.os.makedirs(all)
    total = 27
    source_dir = shutil.os.path.join(loc,"my_code")

    files = shutil.os.listdir(source_dir)

    for i in range(total):
        folder_name = shutil.os.path.join(all, str(i+1))
        shutil.os.makedirs(folder_name)
        destination_dir = folder_name

        for file_name in files:
            source_file = shutil.os.path.join(source_dir, file_name)
            if shutil.os.path.isfile(source_file):
                destination_file = shutil.os.path.join(destination_dir, file_name)
                shutil.copy(source_file, destination_file)