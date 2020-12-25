# Code Quality Inspection (CQL)

## DEMO
![DEMO](https://i.imgur.com/MZeadP5.png)

## Build

```shell script
./mvnw install -DskipTests
```

## Contribution

All the contributions must follow the rules:

1. Every java file must be attached a Apache License header.
2. Must follow the java naming conventions.

And commit your contributions in the following steps:

1. You must create a new branch for every change request (aka PR).
    - The branch name must be `${tag}/${issue-number}`
        - e.g. For a dev ticket of issue number 35, it's `dev/35`
2. When your changes have been done, run `./mvnw package` to make sure all the tests are passed.
3. Make sure your branch has a same **base** as the remote Main branch's.
    - If not, run: 
        1. `git checkout main`
        2. `git pull origin main`
        3. `git checkout ${branch's name}`
        4. `git rebase main`
            1. If there exists conflicts.
            2. Solve the conflict then run `git add .`
            3. `git rebase --continue`
            4. Repeat until all conflicts solved
        5. `git push --force-with-lease origin ${branch's name}` to the latest version of the `main` branch.
4. Create a Pull Request with a sufficient description, create the PR.
5. **Link the PR to the issues that it covers.**
6. Add Reviewer requests.


