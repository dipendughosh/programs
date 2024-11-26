---
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
    - `1_sky_view_open/gnss_log_2024_11_21_10_11_07.txt`
    - `2_sky_view_partial/gnss_log_2024_11_21_09_33_45.txt`
    - `3_sky_view_limited/gnss_log_2024_11_21_09_05_55.txt`

- **images**  
  Folder containing additional provided images.
  - `image1.jpg`, `image2.jpg`, `image3.jpg`, `image4.jpg`, `image5.jpg`, `image6.jpg`

---

## How to Run the Code?

### Part-A

- Simply unzipping and running the notebook from as is should run with the existing logs provided.
- To run with other logs either the logs needs to be placed at the locations mentioned in the `Pre-Processing` section or modifying the `log_file_paths` variable in the `Pre-Processing` section.

1. **Log File Pre-processing**

   - In the notebook, locate the "Pre-processing" section.
   - The variable `log_file_paths` contains the paths to GNSS log files for the three scenarios. Update these paths if required.

2. **Tasks and Observations**
   - Each task is implemented in its respective section of the notebook.
   - Observations are provided following each task's implementation.

---
