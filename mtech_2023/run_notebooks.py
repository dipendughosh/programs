from nbconvert.preprocessors import ExecutePreprocessor
import nbformat
import shutil

assNo = 2

for j in range(assNo):

    ass = "ass"+str(j+1)
    loc = shutil.os.path.join("/home/dipendu/programs/mtech_2023/ml",ass)
    all = shutil.os.path.join(loc,"all")
    total = 27

    for i in range(total):
        folder_name = shutil.os.path.join(all, str(i+1))
        notebook_files = shutil.os.listdir(folder_name)
        for notebook_file in notebook_files:
            notebook_file = shutil.os.path.join(folder_name, notebook_file)
            print("working on : ", notebook_file)
            with open(notebook_file, "r", encoding="utf-8") as f:
                notebook = nbformat.read(f, as_version=4)
            executor = ExecutePreprocessor(timeout=-1)
            executor.preprocess(notebook, {"metadata": {"path": "./"}})
            with open(notebook_file, "w", encoding="utf-8") as f:
                nbformat.write(notebook, f)
