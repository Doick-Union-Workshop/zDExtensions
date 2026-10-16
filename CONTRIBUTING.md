# Contributing Guidelines

Thank you for contributing to this project!
To keep commit history clean and consistent, follow the [Conventional Commits](https://www.conventionalcommits.org/) specification.

## Source layout

Engine-specific implementations belong in `src/**/*.ipp`, inside `namespace GOTHIC_NAMESPACE`.
CMake generates a separate translation unit for each enabled engine from `src/IppFileTemplate.in`,
which supplies the engine macros and `HOOKSPACE`. New `.ipp` files are discovered automatically;
do not include them from other source files.

Keep shared declarations and templates in headers with include guards, and include dependencies
explicitly in each module. Put engine-independent implementations in `.cpp` files.

Each external module declares its functions in `Externals_<module>.hpp` and includes that header
from its `.ipp` implementation. Function template definitions live in the header so other modules
can instantiate them; `Externals_Utils.hpp` contains only templates and needs no `.ipp` file.

`Externals/Externals_Definitions.ipp` owns the central BDE table and native parser registrations.
`Plugin.ipp` includes `Externals/Externals_Definitions.hpp` and calls `zDExt_DefineExternals()`
from the game callback.

## Commit Messages

Each commit message **must** follow this format:

```yml
<type>[optional scope]: <description>
```

- **type** – describes the category of change (see below)  
- **scope** – optional, specifies the part of the codebase, e.g. `externals` or `hooks`
- **description** – short summary in present tense, lowercase, no period at the end

## Commit Types

- **feat** – a new feature
- **fix** – a bug fix
- **docs** – documentation only changes (e.g. README, comments)
- **style** – formatting, whitespace, missing semicolons, etc. (no code changes)
- **refactor** – code change that neither fixes a bug nor adds a feature
- **perf** – performance improvement
- **build** – changes to the build system or external dependencies
- **ci** – changes to CI/CD configuration files
- **chore** – other changes

## Examples

```yaml
✅ Correct:
feat: add helper to check if NPC is player
fix: resolve crash in HandleSlotChange hook
docs: document oCNpc::Hook_EV_DropVob
refactor: simplify sky controller override
chore: bump version to 1.2.3
```

```yaml
❌ Incorrect:
Added new NPC check
Bugfix for menu
Docs update
````

## Additional Notes

- Use **English** in commit messages.  
- Keep descriptions concise (50 characters max).  
- If a commit closes an issue, use `Closes #123` in the commit body.
