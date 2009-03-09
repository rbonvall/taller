all: index.html clase1.html

%.html: %.rst
	rst2html --stylesheet-path=lsr.css --link-stylesheet $^ $@
	recode u8..h -d $@

clean:
	rm *.html
