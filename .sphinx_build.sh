#!/bin/bash

sphinx-build -b html docs _build
sphinx-autobuild . _build/


