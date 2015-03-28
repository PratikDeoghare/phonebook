

readme.pdf: readme.tex img/
	pdflatex readme.tex
	pdflatex readme.tex
	pdflatex readme.tex
	rm *.aux *.log *.toc

