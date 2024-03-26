# def inverse(matrix):
#     # Initialize the augmented matrix by adding the identity matrix
#     n = len(matrix)
    
#     augmented_matrix = []  # Initialize an empty list to store the augmented matrix

#     # Iterate over each row index i and corresponding row row in the original matrix
#     for i, row in enumerate(matrix):
#         # Create a new row for the augmented matrix by appending the identity matrix column
#         new_row = row + [1 if i == j else 0 for j in range(n)]
#         # Append the new row to the augmented matrix
#         augmented_matrix.append(new_row)
        
#     # Gaussian elimination
#     for i in range(n):
#         # Normalize the current row
#         pivot = augmented_matrix[i][i]
#         for j in range(n * 2):
#             augmented_matrix[i][j] /= pivot
#         # Eliminate non-zero elements below the pivot
#         for k in range(n):
#             if k != i:
#                 factor = augmented_matrix[k][i]
#                 for j in range(n * 2):
#                     augmented_matrix[k][j] -= factor * augmented_matrix[i][j]

#     # Extract the inverse matrix from the augmented matrix
#     inverse_matrix = [row[n:] for row in augmented_matrix]

#     return inverse_matrix

# # Example 6x6 matrix
# matrix_6x6 = [
#     [1, 2, 3, 4, 9, 6],
#     [2, 4, 6, 8, 18, 12],
#     [3, 6, 9, 12, 27, 18],
#     [4, 8, 12, 16, 36, 24],
#     [9, 18, 27, 36, 81, 54],
#     [6, 12, 18, 24, 54, 36]
# ]

# # Calculate the inverse
# inverse_matrix_6x6 = inverse(matrix_6x6)

# # Print the inverse matrix
# print("Inverse of the 6x6 identity matrix:")
# for row in inverse_matrix_6x6:
#     print(row)

# def inverse(matrix):
#     # Check if the matrix is 6x6
#     if len(matrix) != 6 or any(len(row) != 6 for row in matrix):
#         raise ValueError("Matrix must be a 6x6 matrix")

#     # Create the augmented matrix by adding the identity matrix
#     augmented_matrix = [row + [1 if i == j else 0 for j in range(6)] for i, row in enumerate(matrix)]

#     # Perform Gauss-Jordan elimination
#     for i in range(6):
#         # Divide each element in the current row by the pivot element
#         pivot = augmented_matrix[i][i]
#         for j in range(12):
#             augmented_matrix[i][j] /= pivot
#         # Subtract multiples of the current row from other rows to make all elements below the pivot zero
#         for k in range(6):
#             if k != i:
#                 factor = augmented_matrix[k][i]
#                 for j in range(12):
#                     augmented_matrix[k][j] -= factor * augmented_matrix[i][j]

#     # Extract the inverse matrix from the augmented matrix
#     inverse_matrix = [row[6:] for row in augmented_matrix]

#     return inverse_matrix

# # # Example 6x6 matrix
# # matrix_6x6 = [
# #     [1, 2, 3, 4, 5, 6],
# #     [0, 1, 0, 0, 0, 0],
# #     [0, 0, 1, 0, 0, 0],
# #     [0, 0, 0, 1, 0, 0],
# #     [0, 0, 0, 0, 1, 0],
# #     [0, 0, 0, 0, 0, 1]
# # ]

# # Example 6x6 matrix
# matrix_6x6 = [
#     [1, 2, 3, 4, 9, 6],
#     [2, 4, 6, 8, 18, 12],
#     [3, 6, 9, 12, 27, 18],
#     [4, 8, 12, 16, 36, 24],
#     [9, 18, 27, 36, 81, 54],
#     [6, 12, 18, 24, 54, 36]
# ]

# # Calculate the inverse
# inverse_matrix_6x6 = inverse(matrix_6x6)

# # Print the inverse matrix
# print("Inverse of the 6x6 matrix:")
# for row in inverse_matrix_6x6:
#     print(row)
    
import numpy as np

# Example 6x6 matrix
# matrix_6x6 = np.array([
#     [1, 2, 3, 4, 5, 6],
#     [0, 1, 0, 0, 0, 0],
#     [0, 0, 1, 0, 0, 0],
#     [0, 0, 0, 1, 0, 0],
#     [0, 0, 0, 0, 1, 0],
#     [0, 0, 0, 0, 0, 1]
# ])

matrix_6x6 = np.array([
    [1, 2, 3, 4, 9, 6],
    [2, 4, 6, 8, 18, 12],
    [3, 6, 9, 12, 27, 18],
    [4, 8, 12, 16, 36, 24],
    [9, 18, 27, 36, 81, 54],
    [6, 12, 18, 24, 54, 1]
])

# Calculate the inverse
inverse_matrix_6x6 = np.linalg.inv(matrix_6x6)

# Print the inverse matrix
print("Inverse of the 6x6 matrix:")
print(inverse_matrix_6x6)
