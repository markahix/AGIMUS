# AGIMUS

Behold **AGIMUS**! The **A**utomated **G**eneralized **I**ntegrated **M**odules for **U**nderstanding **S**tructures.

### Introduction

Machine learning has proven to be a highly powerful tool for contemporary computational chemistry
efforts, particularly in the identification and prediction of important physicochemical properties. The
quality of ML models is dependent, first and foremost, upon the accuracy, scope, and scale of the
training dataset which is made available. The training data must have values which are as close
to the true value as possible, spans as much of the range of each value as possibile, and with as
many entries as can reasonably be obtained as possible. For example, a model meant to predict
the fluorescence properties of proteins relies on a dataset that covers at minimum the complete
visible spectrum. If its training dataset only covers between 500nm and 700nm, the model cannot
reasonably predict values outside this range. If there are too few entries, the model will be unable
to identify relevant features or provide sufficient precision in its predicted values.

We can perform classical molecular dynamics simulations combined with hybrid quantum
mechanics/molecular mechanics (QM/MM) calculations to obtain useful theoretical values for
fluorescence data, however these simulations are time-intensive and involve a number of complex
steps with many separate programs and analytical suites. To ensure consistency of data
generation as well as improved repeatability, we have developed an automated workflow which
can programmatically identify important features of a given biomolecular system, then perform
a complete computational sequence to obtain desired values which are included in the final ML
training/testing dataset.

### Methodology

Questions in computational chemistry are as varied as the molecules under study. 
As such, the generalizability of an automated workflow is dependent on its ability to adapt to systems of different size and composition as well as the nature of the information being sought. 
In pursuit of this versatility, we constructed several independent and self-contained modules which can perform task-specific calculations as part of the larger process for a given system. 
Each module is designed to be command-line callable and was built to work in a high-performance computing (HPC) environment with job scheduling capabilities (i.e. SLURM).

### Setup and Installation

Each module is maintained as an independent repository which can be installed separately, or the end-user may simply download the entire suite here.

