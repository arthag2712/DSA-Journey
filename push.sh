#!/bin/bash

echo "Enter commit message:"
read msg

git add .

git commit -m "$msg"

git push

echo ""
echo "✅ Successfully pushed to GitHub!"