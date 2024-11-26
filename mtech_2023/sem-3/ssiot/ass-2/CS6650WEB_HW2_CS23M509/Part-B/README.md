# Project Overview

This repository contains code, data, and resources for analyzing GNSS measurements and performing localization tasks. The folder structure after unzipping the provided zip file is as follows:

## Requirements

To run this project, you will need the following Python packages:

- `ipykernel`
- `pandas`
- `matplotlib`
- `scikit-learn`
- `tensorflow`
- `nbconvert`
- `nbformat`
- `opencv-python`
- `scipy`
- `seaborn`
- `tabulate`

You can install these packages using pip:

```bash
pip install ipykernel pandas matplotlib scikit-learn tensorflow nbconvert nbformat opencv-python scipy seaborn tabulate
```

---

## Folder Structure

### Part-B

- **PartB_Localization.ipynb**  
  Jupyter notebook for performing IoT localization tasks.

- **Report.pdf**  
  Report detailing the results and observations.

- **dipendu_data**  
  Folder containing generated data files.

  - `noisy_locs_05.csv`, `noisy_locs_1.csv`, `noisy_locs_2.csv`
  - `noisy_ranges_05.csv`, `noisy_ranges_1.csv`, `noisy_ranges_2.csv`
  - `pure_locs.csv`, `pure_ranges.csv`, `true_locations.csv`

- **images**  
  Folder containing additional provided images.
  - `image1.jpg`, `image2.jpg`

---

## How to Run the Code?

### Part-B

- Simply unzipping and running the notebook from as is should run.
- To execute with the provided logs skip running the data generation code part.

1. **Task 1: Data Generation**

   - The code for data generation is split into two sections:
     - **Section 1:** Defines file paths. Run this section if working with provided data without generating new random data.
     - **Section 2:** Contains random data generation logic. Execute this section to generate new random data for each run.

2. **Task 2: Random Node Selection**

   - Two random numbers (A and B) are selected for random node selection.
   - The described tasks are then implemented using the selected node and anchor locations.

3. **Task 3: Solving Node Locations**
   - The `lmfit` library is used to estimate node locations based on range data.
   - Results are rounded to the nearest integer values and written to output files.

---
