#!/bin/bash

cd docs
make html
sphinx-autobuild . build/html/


