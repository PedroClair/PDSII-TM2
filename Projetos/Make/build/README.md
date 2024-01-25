# Correct bug caused by lack of build folder

- git checkout -b iss53
- - create this readme and build folder.
- git add -a -m "solve hotfix first"
- git checkout -b hotfix
- git add -a -m "ford car is not running"
- git checkout main (return to main branch)
- git merge hotfix
- git branch -d hotfix (delete hotfix branch)
- - complete the informations in this readme and build folder.
- git commit -a -m "Finish the new footer [issue 53]"
- git merge main

