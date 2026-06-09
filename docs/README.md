# zDExtensions Docs

Project documentation is built using [Zensical](https://zensical.org/) and managed with [uv](https://github.com/astral-sh/uv) – a fast Python dependency and environment manager.

## Requirements

- [Python 3.10+](https://www.python.org/downloads/)
- [uv](https://github.com/astral-sh/uv) (recommended for environment automation)
- [Visual Studio Code](https://code.visualstudio.com/Download) ([Python](https://marketplace.visualstudio.com/items?itemName=ms-python.python) and [Pylance](https://marketplace.visualstudio.com/items?itemName=ms-python.vscode-pylance) extensions)

## Quick Start

### 1. Install dependencies and environment

In the `docs/` directory, run:

```sh
uv venv
uv pip install -e .[dev]
```

### 2. Start documentation server (hot reload)

```sh
uv run zensical serve
```

### 3. Build static site

```sh
uv run zensical build
```

## Additional Information

- Zensical configuration: `zensical.toml`
- Project dependencies and settings: `pyproject.toml`
- Source documentation: `docs/docs/`
