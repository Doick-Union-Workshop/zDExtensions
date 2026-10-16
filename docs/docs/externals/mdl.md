# MDL – NPC model functions

These functions update an individual visual field and call `InitModel()` to refresh the NPC model immediately. An invalid NPC causes no change.

## zDExt_Mdl_SetVisualBody

Sets the NPC body visual.

```dae
func void zDExt_Mdl_SetVisualBody(var C_NPC npc, var string body) {};
```

- `npc` – NPC to update
- `body` – body visual name

```dae title="Example usage"
zDExt_Mdl_SetVisualBody(hero, "HUM_BODY_NAKED0");
```

## zDExt_Mdl_SetVisualBodyTexture

Sets the body texture variation.

```dae
func void zDExt_Mdl_SetVisualBodyTexture(var C_NPC npc, var int bodyTexNr) {};
```

- `npc` – NPC to update
- `bodyTexNr` – body texture variation index

```dae title="Example usage"
zDExt_Mdl_SetVisualBodyTexture(hero, 0);
```

## zDExt_Mdl_SetVisualBodySkinTexture

Sets the body skin texture color variation.

```dae
func void zDExt_Mdl_SetVisualBodySkinTexture(var C_NPC npc, var int bodySkinTexNr) {};
```

- `npc` – NPC to update
- `bodySkinTexNr` – body skin texture color index

```dae title="Example usage"
zDExt_Mdl_SetVisualBodySkinTexture(hero, 0);
```

## zDExt_Mdl_SetVisualHead

Sets the NPC head visual.

```dae
func void zDExt_Mdl_SetVisualHead(var C_NPC npc, var string head) {};
```

- `npc` – NPC to update
- `head` – head visual name

```dae title="Example usage"
zDExt_Mdl_SetVisualHead(hero, "HUM_HEAD_PONY");
```

## zDExt_Mdl_SetVisualHeadTexture

Sets the head texture variation.

```dae
func void zDExt_Mdl_SetVisualHeadTexture(var C_NPC npc, var int headTexNr) {};
```

- `npc` – NPC to update
- `headTexNr` – head texture variation index

```dae title="Example usage"
zDExt_Mdl_SetVisualHeadTexture(hero, 0);
```

## zDExt_Mdl_SetVisualTeethTexture

Sets the teeth texture variation.

```dae
func void zDExt_Mdl_SetVisualTeethTexture(var C_NPC npc, var int teethTexNr) {};
```

- `npc` – NPC to update
- `teethTexNr` – teeth texture variation index

```dae title="Example usage"
zDExt_Mdl_SetVisualTeethTexture(hero, 0);
```
