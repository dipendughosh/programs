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

## Folder Structure

### Part-A
- **PartA_GNSS_Measurements.ipynb**  
  Jupyter notebook for analyzing GNSS measurements and observations.

- **dipendu_data**  
  Folder containing sky visibility images and GNSS logs.
  - **images**
    - `1_sky_view_open/IMG_20241110_141155.jpg`
    - `2_sky_view_partial/IMG_20241110_135352.jpg`
    - `3_sky_view_limited/IMG_20241110_132521.jpg`
    - `azimuth_calculation/`
      - `azimuth_calculation.jpg`
      - `my_location.jpg`
  - **logs**
    - `1_sky_view_open/gnss_log_2024_11_14_12_48_41.txt`
    - `2_sky_view_partial/gnss_log_2024_11_14_11_51_40.txt`
    - `3_sky_view_limited/gnss_log_2024_11_14_12_31_38.txt`

- **images**  
  Folder containing additional provided images.
  - `image1.jpg`, `image2.jpg`, `image3.jpg`, `image4.jpg`, `image5.jpg`, `image6.jpg`

---

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

### Part-A
1. **Log File Pre-processing**  
   - In the notebook, locate the "Pre-processing" section.  
   - The variable `log_file_paths` contains the paths to GNSS log files for the three scenarios. Update these paths if required.

2. **Tasks and Observations**  
   - Each task is implemented in its respective section of the notebook.  
   - Observations are provided following each task's implementation.

---

### Part-B
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
   