@echo off

set size=600x
set quality=80

magick mogrify -format jpg *.png
magick mogrify -format jpg *.jpeg
magick mogrify -resize %size% *.jpg
magick mogrify -strip -quality %quality% *.jpg