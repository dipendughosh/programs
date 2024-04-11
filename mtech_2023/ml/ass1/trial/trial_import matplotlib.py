import matplotlib.pyplot as plt
import numpy as np

# Create a 3D figure
fig = plt.figure()

# Add 3D axes to the figure
ax = fig.add_subplot(111, projection='3d')

# Generate some data
x = np.linspace(-5, 5, 100)
y = np.linspace(-5, 5, 100)
X, Y = np.meshgrid(x, y)
Z = np.sin(np.sqrt(X**2 + Y**2))

# Plot the 3D surface
ax.plot_surface(X, Y, Z)

# Set labels and title
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('3D Plot')

# Show the plot
plt.show()
