from PIL import Image, ImageFilter


# Open file to make blur
before = Image.open("yard.bmp")
# Apply filter
after = before.filter(ImageFilter.BLUR)
# Output to file
after.save("out.bmp")