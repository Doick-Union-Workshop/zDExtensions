# Log functions

## zDExt_Log_GetTopicStatus

Gets the status of diary topic. Works only for missions, not for notes.

- `0` – Free
- `1` / `LOG_RUNNING` – Running
- `2` / `LOG_SUCCESS` – Success
- `3` / `LOG_FAILED` – Failure
- `4` / `LOG_OBSOLETE` – Obsolete

```dae
func int zDExt_Log_GetTopicStatus(var string topic) {};
```

- `topic` – name of the mission topic
- `return` – topic status

```dae title="Example usage"
if (zDExt_Log_GetTopicStatus(TOPIC_InnosEye) == LOG_SUCCESS)
{
    //...
};
```
