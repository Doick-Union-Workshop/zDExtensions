namespace GOTHIC_NAMESPACE
{
    /*
     *
     * Created by Boguś (bogu9821), 2025
     * Original source: https://gist.github.com/bogu9821/08b938ef9a5a38fab467d5eac3aa3b0d
     *
     */
    template<typename T>
    int _cdecl zDExt_GetArrayValue()
    {
        const auto par = zCParser::GetParser();

        int index;
        par->GetParameter(index);

        const auto statArray = reinterpret_cast<T*>(par->PopVarAddress());

        par->SetReturn(statArray[index]);

        return {};
    }

    /*
     *
     * Created by Boguś (bogu9821), 2025
     * Original source: https://gist.github.com/bogu9821/08b938ef9a5a38fab467d5eac3aa3b0d
     *
     */
    template<typename T>
    int _cdecl zDExt_SetArrayValue()
    {
        const auto par = zCParser::GetParser();

        T value;
        par->GetParameter(value);

        int index;
        par->GetParameter(index);

        const auto statArray = reinterpret_cast<T*>(par->PopVarAddress());

        statArray[index] = static_cast<T&&>(value);

        return {};
    }
}
