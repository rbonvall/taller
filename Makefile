all: index.html clase2.html clase3.html clase4.html clase5.html clase6.html

%.html: %.rst
	rst2html --stylesheet-path=lsr.css --link-stylesheet $^ $@
	recode u8..h -d $@

clean:
	rm *.html
