@echo off

set size=800x
set quality=65

magick mogrify -format jpg *.png
magick mogrify -format jpg *.jpeg
magick mogrify -resize %size% *.jpg
magick mogrify -strip -quality %quality% *.jpg