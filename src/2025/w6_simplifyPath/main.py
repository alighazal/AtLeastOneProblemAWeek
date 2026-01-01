class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        #/home/user/Documents/../Pictures
        #/home/user/Pictures

        path_components = path.split('/')
        simplified_path = []
        for component in path_components:
            if not component:
                continue
            if component == "..":
                if (len(simplified_path)):
                    simplified_path.pop()
            elif component == ".":
                continue
            else:
                simplified_path.append( component )

        return '/' + '/'.join(simplified_path)
