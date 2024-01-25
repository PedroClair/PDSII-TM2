# Correct bug caused by lack of build folder

## Start the issue
- git checkout -b iss53
- - create this readme and build folder.

## Stop to solve the hotfix
- git add -a -m "solve hotfix first"
- git checkout -b hotfix
- git add -a -m "ford car is not running"

## Return to main branch and finish the hotfix branch
- git checkout main (return to main branch)
- git merge hotfix
- git branch -d hotfix (delete hotfix branch)

## Return to issue
- git checkout iss53
- - complete the informations in this readme and build folder.
- git commit -a -m "Finish the new footer [issue 53]"
- git merge main (hotfix solution)
- - complete the informations in this readme and finish it.
- git commit -a -m "Finish the new footer [issue 53]"

## Return to main
- git checkout main
- git merge iss53
- git commit -a -m "issue 53 up to main"

